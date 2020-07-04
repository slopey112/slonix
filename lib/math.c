int pow(int x, int n) {
    int total = 1;
    for (int i = 0; i < n; i++) {
        total *= x;
    }
    return total;
}
