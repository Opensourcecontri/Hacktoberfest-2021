#!/usr/bin/env python
# coding: utf-8

# In[ ]:


colors = ['red','yellow','green','blue','black']
for color in colors:
     print (color)


# In[ ]:


for index, color in enumerate(colors):
    print (index, color)


# In[ ]:


msg = "Hi"
for i in msg:
    print(i)          


# In[ ]:


for i in range(5):
    print(i)        


# In[ ]:


for i in range(3,10):
    print(i)


# In[ ]:


for i in range(4,10,2):
    print(i)


# In[ ]:


a = 0
for i in range(10):
    a = + 2
    print ('i = ', i, 'a = ',a)
    if a== 4:
        break


# In[ ]:


for i in range(10):
    print ('i = ', i)


# In[ ]:


for num in range(3):
    if num == 1: 
        continue 
    print('Current number :', num)


# In[ ]:


for num in range(3):
        print('Current number :', num)


# In[ ]:




