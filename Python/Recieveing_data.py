import csv
import imaplib
import email
from email.header import decode_header

def get_data():
    strhere=[[]]
    username = "akshay.kushawaha@gmail.com"
    password = "Enter password here"
    imap_server = "imap.gmail.com"
    imap = imaplib.IMAP4_SSL(imap_server)
    imap.login(username, password)
    imap.select("INBOX")
    status, message = imap.search(None, '(FROM "PhonePe" SUBJECT "Sent")')

    message=str(message)
    message=message[3:-2:]
    messages=message.split(" ")
    
    status, message = imap.search(None, '(FROM "PhonePe" SUBJECT "Received")')
    message=str(message)
    message=message[3:-2:]
    message=message.split(" ")
    messages=message+messages
    message.sort()
    N=0
    print(len(messages))
    file1 = open("C:/Users/aksha/Documents/Projectflexi/email_data.txt","w")
    for i in messages:
        # fetch the email message by ID
        res, msg = imap.fetch(str(i), "(RFC822)")
        for response in msg:
            N+=1
            if isinstance(response, tuple):
                # parse a bytes email into a message object
                msg = email.message_from_bytes(response[1])
                # decode the email subject
                subject, encoding = decode_header(msg["Subject"])[0]
                if isinstance(subject, bytes):
                    # if it's a bytes, decode to str
                    try:
                        subject = subject.decode(encoding)
                        if "Sent ₹" in subject:
                            subject=subject.split("to")
                            amount=int(subject[0][14:])
                            sender=subject[1][2:]+" , -"
                            time=msg["date"][17:25]
                            date=msg["date"][4:16]
                        if "Received ₹" in subject :
                            subject=subject.split("from")
                            amount=int(subject[0][17:])
                            sender=subject[1][2:]+" , +"
                            time=msg["date"][17:25]
                            date=msg["date"][4:16]
                        text=date+" , "+time+" , "+sender+str(amount)+"\n"
                        print(N,".  ",text)
                        file1.write(text)
                    except:
                        pass

    # close the connection and logout  
    file1.close()                
    imap.close()
    imap.logout()
    
get_data()
