# PhotoMagic

# PS1: PhotoMagic

## Contact
Name: Truong-Thinh Huynh
Section: 201
Time to Complete: 7 Hours


## Description
Explain what the project does.

PS1b: PhotoMagic as a whole is meant to built onto Ps1a: FibLFSR which is where we created a FibLFSR. In our PhotoMagic, we are suppposed to encrypt an input image into an output image that is unrecognizable comparing to the input image. In order to encrypt the image, I utilized the FibLFSR generate() function that will scambled the pixels of the image, and such instructions will be run in transform() function, which is a function we have to write for PS1b. The reason for using generation() function was to encrypt the image pixels by changing the pixel's color components, which is its RGB value. It does this by calling generate() function to return a value, and this value will be our encryption, which is then XOR onto the current RGB value. As a result of XORing our RGB value, the pixels will change its color, and as the entire image changes color, the image will be change dramatically. In addition to scambling our image, we are allowed to use codes provided by Dr. Daly which basically set up a huge portion of our project by opening two windows and taking in an input image, output image and the seed for the encryption and decryption. The project also supported command line arguments that could also take in input image, output image and the seed as well. But another important function of the project is that we could also decrypt out encrypted image by placing the encrypted image as our input image, which decrypt that image into the original image if implemented properly.

### Features
Describe what your major decisions were and why you did things that way.

My first major decision that I decided were changing the for loop to run x and y based on the image.x and image.y instead of putting the image's dimension of x and y in it by hand. The reason is  by having image.x and image.y, it saved me time from changing the dimension everytime I decided to use a different image as it will automatically uses the image's dimension.

My second major decision that I decided were instead of combining the codes to work for both alphanumeric and binary of 0 and 1, I seperated into two. The reason is that if I somehow failed to implemented the extra credit to work properly, it will also failed the implemented for the binary, which will not give me any extra credit, it also reduce points for the required parts of the project as it will not work. Therefore in every FibFLSR's functions and in PhotoMagic, I have a private data called isAlphanumeric that determine which block of instructions to run if it is alphanumeric or not. This is definitely not the most optimize, but it is to fully secure that my required parts of the project won't failed because the extra credit part failed.

My third major decision that I decided is in the alphanumeric block of instructions. I have restricted the generate(), step(), transform(), etc., everything line of codes that uses the input string of alphanumeric is changed to the size of input string instead of 16 bit like the string of 0 and 1 because the string for alphanumeric could be less or more than 16 characters. This is why it would makes sense to computate using the size of the string.

My fourth major decision that I decided is to put the XOR function that XORing alphanumeric in private data, as it is only a helper function that shouldn't be able to be call outside of the class as it is only needed to XOR two char together. 

HOW TO USE:

This project could be utilize by giving an input file, output file, and the seed straight into the code of blocks by inputting the name of the files and seed. But it could also takes in command line arguments by providing it needed files by doing ./PhotoMagic input-file.png output-file.png seedname.

Also for this project, the seed also works for string of characters that isn't 0 or 1. And input file and output file could be switched so that it could do both encrypt and decrypt.

### Issues
What doesn't work.  Be honest.  You might be penalized if you claim something works and it doesn't.

Everything works as I intended but during my extra credit of testing the encryption using only characters, while it still scambled the image beyond recognition, the outline is very little being visible, but you still won't be able to make out what the image is, even if you have the original image next to it. Despite that, it is still there and that is something that should be mentioned.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

For my extra credit, in order to me to convert alphanumeric password into something that could encrypt the image is through ASCII. I realized that each character has an ASCII associating it to a decimal value. So I could take these decimal values and XORing it to each other to get a result. This result could be conveted back into ASCII character by using it decimal value. This allowed me to push the XOR character conversion back into the string and then have the decimal value be return by step() and generate(). So it allowed me to fulfilled the requirement that step() and generate() must be able to return int while being able to push a char into the new seed. Of course, my project also recognize if the seed is alphanumeric or not, if it is, then it is only running block of codes needed to make the alphanumeric password work.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

// Use for finding decimal value of char
https://www.asciitable.com

// Use for calculating whether or not my step() and generate() works properly for alphanumeric
https://xor.pw
