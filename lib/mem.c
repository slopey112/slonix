/*
 * NAME: lib_memory_copy
 *
 * PARAMETERS:
 *     void source    A pointer to a memory region designated as the source of the memory copy.
 *     void dest      A pointer to a memory region designated as the destination of the memory copy.
 *     int nbytes     N number of bytes to copy.
 *
 * RETURNS:
 *     void
 *
 */
void lib_memory_copy(void *source, void *dest, int nbytes) {
    unsigned char *c_source = (unsigned char *) source;
    unsigned char *c_dest = (unsigned char *) dest;

    for (int i = 0; i < nbytes; i++)
        *(c_dest + i) = *(c_source + i);
}

void memset(void *array, unsigned char byte, int nbytes) {
    unsigned char *c_array = (unsigned char *) array;
    
    for (int i = 0; i < nbytes; i++)
        *(c_array + i) = byte;
}
