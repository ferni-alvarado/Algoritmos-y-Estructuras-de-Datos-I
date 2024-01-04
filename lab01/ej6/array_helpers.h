
void array_swap(int a[], unsigned int i, unsigned int j);
 

bool array_is_sorted(int a[], unsigned int max_size);
/* checking whether the array is sorted or not */

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath);
/* parse the file to fill the array and obtain the actual length */           
           
void array_dump(int a[], unsigned int length);

/* Dumping the array */

