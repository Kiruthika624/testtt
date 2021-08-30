# Heap Analysis Tool

## Requirements
1. The tool will check the following parameters:
    * Usage of heap at sampling point.
    * Max usage of heap with and without tool overhead.
    * The tool overhead heap at sampling point and overall.
    * Print largest heap allocation request without overhead
    * Per function analysis.
    * Top level allocation functions.
 
2. The tool will override the following functions:
    * malloc
    * realloc
    * calloc
    * free
3. the tool should be portable and be able to work platform independent
4. the tool can be activated with compilation flag
 
## Design
The tool will maintain a structure containing all the wanted counters
This may appear obvious, but is the core of the design. **those counters will be updated upon allocation and release memory from the heap.**
The structure is:
```
typedef struct _HEAP_ANALSYS_DATA
{
unsigned int currentHeapUsge;
unsigned int maxHeapUsge;
unsigned int currentOverheadUsge;
unsigned int maxOverheadUsge;
unsigned int maxTotalUsge;
}HEAP_ANALSYS_DATA;
```
* currentHeapUsge – Number of bytes currently allocated on heap
* maxHeapUsge - Max number of bytes that were allocated from heap
* currentOverheadUsge- Heap analyses tool usage of heap memory
* maxOverheadUsge - Max number of memory allocated from heap by heap analyses tool
* maxTotalUsge - Max bytes allocated from heap

When dynamically allocating memory the malloc function will allocate extra place to save the required data to manage the memory usage.
This is essential to maintain the counter while freeing pre-allocated memory. 
The allocation functions will return the pointer to the data.

## APIs What about calloc, realloc, new, delete, etc… ?
 
* void* __wrap_malloc(size_t size) – will replace malloc and will allocate size bytes from the heap, this will allocate sizeof(size_t) additional bytes for internal use.
 
* void __wrap_free(void* ptr) – returning a pre-allocated memory to the heap
 
* void* __wrap_calloc(size_t num, size_t size) – will replace malloc and will allocate size bytes from the heap and set them to be zeros, this will allocate sizeof(size_t) additional bytes for internal use.

* To activate the tool add the ```PAL_MEMORY_STATISTICS , PAL_MEMORY_PRINT_DATA , PAL_MEMORY_BUCKET``` to compiler defines in Makefile.

* To get stats for a single function just wrap it in a one of the 2 defines:
    * TEST_FUNCTION_NO_ARGS("test_new",test_new);
    * TEST_FUNCTION("test_one_arg",test_one_arg,a);
Those defines are in the arm_malloc.h file.