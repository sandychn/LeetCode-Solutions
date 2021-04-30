int maximum(int a, int b) {
    long long diff = a;
    diff -= b;
    int sign = (diff >> 63) & 1;  // a >= b, a - b >= 0, sign = 0
    return (a * (sign ^ 1)) | (b * sign);
}
