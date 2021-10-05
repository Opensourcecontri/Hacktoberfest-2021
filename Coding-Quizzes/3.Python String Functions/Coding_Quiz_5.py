job_des = " are you working as a Python programmer?"
job_des_vowel_lower_count = job_des.count('a') + job_des.count('i') +job_des.count('o')+job_des.count('u')+job_des.count('e')
job_des_vowel_upper_count = job_des.count('A')+job_des.count('E')+job_des.count('O')+job_des.count('U')+job_des.count('I')
job_des_vowel_count = job_des_vowel_lower_count + job_des_vowel_upper_count
print(job_des_vowel_count)