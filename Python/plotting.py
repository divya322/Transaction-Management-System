import matplotlib.pyplot as plt
import csv
import pandas as pd
import collections
import datetime

x = []
y = []

with open('Transactions.csv','r') as csvfile:
	plots = csv.reader(csvfile, delimiter = ',')
	
csvfile=open('Transactions.csv','r')
data=csv.reader(csvfile, delimiter = ',')
date_list=[]
name_list=[]

for row in data:
    if row[0]!="Date":
        date_list.append(row[0])
        name_list.append(row[2])

csvfile.close()
date_counter = dict(collections.Counter(date_list))
name_counter = dict(collections.Counter(name_list))
nc = dict(collections.Counter(name_list))
for i in nc.keys():
    if name_counter[i]<=2:
        del name_counter[i]
dc = dict(collections.Counter(date_list))
    

name_list=list(name_counter.keys())
name_freq=list(name_counter.values())
date_list=list(date_counter.keys())
date_freq=list(date_counter.values())
for i in range(len(date_list)):
    month=date_list[i].split(" ")
    datetime_object = datetime.datetime.strptime(month[2], "%b")
    month[2] = datetime_object.month
    print("here: ",month)
    if len(month[1])==1:
        month[1]="0"+month[1]
        print("here: ",month)
    month = ''.join(str(x) for x in month)
    date_list[i]=month
print(date_list)

fig, ax = plt.subplots()
ax.plot(name_list, name_freq)
plt.autoscale()
plt.xlabel('Date')
plt.ylabel('Frequency')
plt.title('money management')
plt.legend()
plt.tick_params(axis='y', which='major', labelsize=10)
plt.tick_params(axis='x', which='major', labelsize=10)
ax.grid(True)
fig.autofmt_xdate()
plt.tight_layout()
plt.show()

s = pd.to_datetime(pd.Series(date_list), format='%d%m%Y')
s.index = s.dt.to_period('m')
s = s.groupby(level=0).size()

s = s.reindex(pd.period_range(s.index.min(), s.index.max(), freq='m'), fill_value=0)
print (s)

s.plot.bar()

'''
fig, ax = plt.subplots()
ax.plot(date_list, date_freq)
plt.autoscale()
plt.xlabel('Date')
plt.ylabel('Frequency')
plt.title('money management')
plt.legend()
plt.tick_params(axis='y', which='major', labelsize=10)
plt.tick_params(axis='x', which='major', labelsize=10)
ax.grid(True)
fig.autofmt_xdate()
plt.tight_layout()
plt.show()'''