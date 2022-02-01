#include <iostream>
#include <vector>
#include <unordered_map>
#include "geom.cpp"

using namespace std;
using namespace geom;

typedef pair<point *, point *> ppp; // point pointer pair

/**
 * @brief Product will be evaluated from the front.
 */
template <class _iterator>
double shoelaceProduct(_iterator, _iterator);

vector<point> &generateShoelace(unordered_map<segment, point> &);

template <class _iterator>
double shoelaceProduct(_iterator ptr, _iterator endPtr)
{
    int size = endPtr - ptr;
    if (size < 3)
        return 0;

    auto crossP = [](const point &p1, const point &p2, const point &p3) -> double
    { return p1.x * p2.y * p3.z - p1.z * p2.y * p3.x; };
    if (size == 3)
        return crossP(ptr[0], ptr[1], ptr[2]);
    else
        return crossP(ptr[0], ptr[1], ptr[2]) - crossP(ptr[1], ptr[2], ptr[3]) + shoelaceProduct(ptr + 2, endPtr);
}

vector<point> &generateShoelace(unordered_map<segment, ppp> &map)
{
    vector<point> result;
    auto startEntry = map.begin();
    ppp pointerPair = startEntry->second;
    segment currSeg = startEntry->first;
    point *const fp = pointerPair.first;
    point *const sp = currSeg.start;
    point *const tp = currSeg.end;
    result.push_back(*fp);
    result.push_back(*sp);
    result.push_back(*tp);

    point *visited = fp;
    // while (result)
    // {

    // }
    return result;
}

int main()
{
    point A(2, 2, 2), B(6, 7, 6), C(6, 15, 4), D(11, 3, 1), E(16, -17, 0);
    point arr[] = {A, B, C, E, D, A, C, B, E, A, D, C, E, B, A, C, D, E, A, B, origin};
    cout << shoelaceProduct(arr, arr + 20) / 6 << endl;
}