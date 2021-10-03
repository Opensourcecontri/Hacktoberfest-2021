def linearSearch(arr,key):
 if key in arr:
 print('Element is present in array')
 else:
 print('Not Found')
if __name__ == "__main__":
 print('Enter the list of the numbers:')
 arr = map(int,input().split())
 arr = list(arr)
 key = int(input('Enter the key element to search: '))
 linearSearch(arr,key)
