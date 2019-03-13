void decode1(long *xp, long *yp, long *zp)
{
    long buf = *xp;
    *xp = *zp;
    *zp = *yp;
    *yp = buf;
}