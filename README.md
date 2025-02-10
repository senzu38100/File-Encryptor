# File-Encryptor
File encryptor in C

------------------ Approach and methodology ------------------
How the encryptor will work?
I will create an out file which will be as following:
	-The first 2 bytes is a random number between 1 and  65 535
	-Then we will have some padding (for instance, if the random number is 400, then
400 bytes of random bytes will follow
	-Then a 256 hash value which is the hashed password or encryption key (which will be used to check if we 
entered the correct password.
	-And finally all the content of the file which will be encrypted using the same key as previously
-----------------------------------------------------------------

