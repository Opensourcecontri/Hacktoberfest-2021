#!/usr/bin/env python
# coding: utf-8

# In[6]:


#In order to check  specific character in a string
'This is user_car'.find('i')


# In[7]:


#In order to check from index 2 to end of a string 
'This is user_car'.find('s', 2)


# In[8]:


#In order to check from index 8 to 12
'This is user_car'.find('s', 8,12 )


# In[9]:


#In order to check special character which is not found in string
# .find() function is like .index() function but differ in the next example: 
'This is user_car'.find('d')


# In[10]:


# .find() function is like .index() function but differ in the next example: 
'This is user_car'.index('d')
ValueError


# In[ ]:




