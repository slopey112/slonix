// THIS DOES NOT WORK YET, DO NOT USE
char *itoa(int num) {
    int len = 0, copy_num = num;
    while (copy_num > 0) {
        copy_num /= 10;
        len++;
    }
    char str[len + 1];
    for (int i = 0; i < len; i++) {
        int digit = num % 10;
        str[len - i - 1] = (char) (digit + 48);
        num /= 10;
    }
    str[len] = '\0';
    return str;
}
