#///////////////////////////////ROW TRANSPOSITION////////////////////////////////////"
'''
import math
  
key = input("Enter the key: ")
  
# Encryption
def encryptMessage(msg):
    cipher = ""
  
    # track key indices
    k_indx = 0
  
    msg_len = float(len(msg))
    msg_lst = list(msg)
    key_lst = sorted(list(key))
  
    # calculate column of the matrix
    col = len(key)
      
    # calculate maximum row of the matrix
    row = int(math.ceil(msg_len / col))
  
    # add the padding character '_' in empty
    # the empty cell of the matix 
    fill_null = int((row * col) - msg_len)
    msg_lst.extend('_' * fill_null)
  
    # create Matrix and insert message and 
    # padding characters row-wise 
    matrix = [msg_lst[i: i + col] 
              for i in range(0, len(msg_lst), col)]
  
    # read matrix column-wise using key
    for _ in range(col):
        curr_idx = key.index(key_lst[k_indx])
        cipher += ''.join([row[curr_idx] 
                          for row in matrix])
        k_indx += 1
  
    return cipher
  
# Decryption
def decryptMessage(cipher):
    msg = ""
    
    # track key indices
    k_indx = 0
  
    # track msg indices
    msg_indx = 0
    msg_len = float(len(cipher))
    msg_lst = list(cipher)
  
    # calculate column of the matrix
    col = len(key)
      
    # calculate maximum row of the matrix
    row = int(math.ceil(msg_len / col))
  
    # convert key into list and sort 
    # alphabetically so we can access 
    # each character by its alphabetical position.
    key_lst = sorted(list(key))
  
    # create an empty matrix to 
    # store deciphered message
    dec_cipher = []
    for _ in range(row):
        dec_cipher += [[None] * col]
  
    # Arrange the matrix column wise according 
    # to permutation order by adding into new matrix
    for _ in range(col):
        curr_idx = key.index(key_lst[k_indx])
  
        for j in range(row):
            dec_cipher[j][curr_idx] = msg_lst[msg_indx]
            msg_indx += 1
        k_indx += 1
  
    # convert decrypted msg matrix into a string
    try:
        msg = ''.join(sum(dec_cipher, []))
    except TypeError:
        raise TypeError("This program cannot",
                        "handle repeating words.")
  
    null_count = msg.count('_')
  
    if null_count > 0:
        return msg[: -null_count]
  
    return msg
  
# Driver Code

mode = input('\nEncrypt or Decrypt?\n')

if mode == 'Encrypt':
    print("\nFor Encryption \n")
    msg = input("Enter the message: ")
    cipher = encryptMessage(msg)
    print("Encrypted Message: {}".format(cipher))
elif mode == 'Decrypt':
    print("\nFor Decryption \n")
    ciphertext = input("Enter the ciphertext: ")
    print("Decryped Message: {}".format(decryptMessage(ciphertext)))
else:
    print("Please Type Encrypt Or Decrypt")
    
# This code is contributed by Aditya K
'''
#////////////////////////////////////AUTOKEY/////////////////////////////////////////"
'''
ALPHA = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def main():
    message = input('Enter the message to be Encrypted or Decrypted: ')
    key = input('Enter the key: ')
    mode = input('Encrypt or Decrypt?\n')
    ## if len(key) < len(message):
        ## key = key[0:] + message[:100]
    #print(key)
    if mode == 'Encrypt':
       print("Encrypted Message: ")
       cipher = encryptMessage(message, key)
    elif mode == 'Decrypt':
       print("Decrypted Message: ")
       cipher = decryptMessage(message, key)
    else:
       print("Please Type Encrypt Or Decrypt")
    
    #print(' message:',  (mode.title()))
    print(cipher)


## def encryptMessage (keys, messages):
##     return cipherMessage(keys, messages, 'encrypt')
def encryptMessage (messages, keys):
    return cipherMessage(messages, keys, 'Encrypt')

## def decryptMessage(keys,messages):
##     return cipherMessage(keys, messages, 'decrypt')
def decryptMessage(messages, keys):
    return cipherMessage(messages, keys, 'Decrypt')


## def cipherMessage (keys, messages, mode):
def cipherMessage (messages, keys, mode):
    cipher = []
    k_index = 0
    key = keys.upper()
    for i in messages:
        text = ALPHA.find(i.upper())
        ## if text != -1:
        if mode == 'Encrypt':
             text += ALPHA.find(key[k_index])
             key += i.upper()  # add current char to keystream

        elif mode == 'Decrypt':
             text -= ALPHA.find(key[k_index])
             key += ALPHA[text]  # add current char to keystream
        text %= len(ALPHA)
        ## k_index += -1
        k_index += 1
        ## if k_index == len(key):
        ##     k_index = 0
        ## else:
        cipher.append(ALPHA[text])
    return ''.join(cipher)

if __name__ == "__main__":
    main()
'''
#//////////////////////////////MONOALPHABETIC//////////////////////////////////
'''
letters = [
           'a','b','c','d','e','f','g','h','i','j','k','l','m',
           'n','o','p','q','r','s','t','u','v','w','x','y','z'
          ]
mode = input('\nEncrypt or Decrypt?\n')
if mode == 'Encrypt':
    print("\nFor Encryption \n")
    text  = str(input("Enter the plaintext: ")).lower()
    key = input("Enter the key: ")
    cipher = []
    for l in text:
        
         key_number =  letters.index(l)
     
         new_letter = key[key_number]
     
         cipher.append(new_letter)
         
    encrypt_text = ''.join(cipher)
    print("Encrypted text: " + encrypt_text)
    
elif mode == 'Decrypt':
    print("\nFor Decryption \n")
    text2  = str(input("Enter the ciphertext: ")).lower()
    key2 = input("Enter the key: ")
    text = []
    for l in text2:

         letter_number =  key2.index(l)

         new_letter = letters[letter_number]

         text.append(new_letter)
         
    orginal_text = ''.join(text)
    print("Decrypted text: " + orginal_text)
else:
    print("Please Type Encrypt Or Decrypt")
'''

 
