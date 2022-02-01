namespace geom
{
    struct point
    {
        double x, y, z;
        point(double x, double y, double z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
    } origin(0, 0, 0);

    struct segment
    {
        point *start, *end;
        segment(point &start, point &end)
        {
            this->start = &start;
            this->end = &end;
        };
    };
}
