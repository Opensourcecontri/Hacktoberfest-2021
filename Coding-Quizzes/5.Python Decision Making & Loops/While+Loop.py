#!/usr/bin/env python
# coding: utf-8

# In[2]:


variable_count= 3
while variable_count > 0:
    variable_count = variable_count - 1
    print ("Variable_count =" , variable_count)


# In[3]:


num = 3 
while num > 0: 
    num -= 1 
    if num == 1: 
        continue 
    print('Current number:', num)


# In[5]:


print(list(zip(['red', 'yellow', 'green'], [1, 2, 3])))


# In[18]:


num = 3 
while num > 0: 
    num -= 1 
    if num == 1: 
        continue
    print('Current number:', num)


# In[7]:


colors = ['red', 'yellow', 'green']
nums = [1, 2, 3]
for color, num in zip(colors, nums):
          print("{}: {}".format(color, num))


# In[8]:


colors = ['red', 'yellow', 'green']
nums = [1, 2, 3]
colors_list = [colors, nums]
for colors, nums in zip(*colors_list):
         print(colors, nums)


# In[9]:


colors = ('red', 'yellow', 'green')
nums = (1, 2, 3)
colors_list = (colors, nums)
for colors, nums in zip(*colors_list):
          print(colors, nums)


# In[11]:


letters = ['a', 'b', 'c', 'd', 'e']
for i, letter in enumerate(letters):
          print(i, letter)


# In[16]:


letters = ('a', 'b', 'c', 'd', 'e')
for i, letter in enumerate(letters):
          print(i, letter)


# In[ ]:




