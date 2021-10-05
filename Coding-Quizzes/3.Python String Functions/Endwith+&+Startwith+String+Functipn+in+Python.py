#!/usr/bin/env python
# coding: utf-8

# In[3]:


#In order to check  if a string contain  specific suffix like car
'user_car'.endswith('car')


# In[4]:


# check from index 4 to end of string
'user_car'.endswith('car', 4)


# In[5]:


#To check from index 5 to 7
'user_car'.endswith('car', 5, 7)


# In[6]:


#To check from index 4 to 8
'user_car'.endswith('car',4, 8)


# In[7]:


#In order to use a tuple of suffixes as we check from index 4 to 8
'user_car'.endswith(('car', 'ar'), 4, 8)


# In[ ]:




