import imapclient ,datetime,pyzmail
conn = imapclient.IMAPClient('imap.gmail.com', ssl=True)
conn.login('ENTER_YOUR_EMAIL','ENTER_YOUR_PASSWORD')
conn.select_folder('INBOX', readonly=True)

UIDs = conn.search(['SINCE',datetime.date(2021,6,1)])
print(UIDs)
print('\n\n')

rawMessage = conn.fetch([360], ['BODY[]','FLAGS'])
message = pyzmail.PyzMessage.factory(rawMessage[360][b'BODY[]'])

Msubject=message.get_subject()
Mfrom=message.get_addresses('from')

print(str(Msubject)+'\n'+str(Mfrom))
try:
    print(message.text_part.get_payload().decode('UTF-8'))  
except :
    pass

conn.logout()
