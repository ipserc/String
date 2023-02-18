# String
Full management and safe string allocation (Under construction)

Most of the time I've created a string in C, I forget that that the amount of memory allocated by malloc is the maximum effective length of the string minus one, because a null termination is required to handle the string properly.

So, the most of the times I want to create a string for, say, 100 characters, I type malloc(100), and then realize that malloc(101) is the correct assignment. Another thing I miss in string manipulation is how to get the maximum effective size of the string, since sizeof(anystring) returns the size of the pointer to allocated memory, not the maximum size of the reserved effective memory for the chain.

With type String, which is a pointer to the _String structure containing two fields, one a char pointer to the actual string and a size_t with the maximum length the string can take and other that keeps a pointer to the memory allocated, the assignment of strings to the variable of type String is safe. The memory allocated is always enough for the size of the string (if you want a 57 character string, you'll get one) and later in your program you can get the effective size of the string, if you want additions or substitutions inside the variable chain.

It has some functions to get all the required information about the maximum length and the amount of reserved memory, as well as a safe and specific method to put your string in the string variable, regardless of the length, because the method takes care that it doesn't overflow the string buffer.
