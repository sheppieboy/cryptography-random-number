import random
from Crypto.Cipher import AES


#!/usr/bin/python3
from Crypto.Cipher import AES


plaintext = bytearray.fromhex('255044462d312e350a25bff7a2fe0a33')
ciphertext: bytearray.fromhex("406ed6d5eba12a69ea7b69bf1ee05b8f")
iv = ("6f6d6567616c756c3132333435363738")

with open('all_possible_keys.txt') as f:
    keys = f.readlines()

for k in keys:
    k = k.rstrip('\n')
    key = bytearray.fromhex(k)
    cipher = AES.new(key=key, mode=AES.MODE_CBC, iv=iv)
    guess = cipher.encrypt(data)
    if guess == ciphertext:
        print("find the key:", k)
        exit(0)

print("cannot find the key!")