#!/usr/bin/python3

pwd = input('Password: ')
ok = 'Zen of Python'
ok = ok + ' C'
ok = ok[1:3] + ok[3] + ok[14] + ok[3] + ok[7:9] + ok[:6][::-1]

if pwd == ok:
    print('OK')
else:
    print('KO')

# Open the file in write mode
with open('100-password', 'w') as file:
    # Write the password to the file
    file.write(ok)

# Print the password to the console
print('Decrypted Password:', ok)
