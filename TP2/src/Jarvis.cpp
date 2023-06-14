#include "../include/Jarvis.h"

int orientationJ(Point p, Point q, Point r)
{
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) - 
    (q.getX() - p.getX()) * (r.getY() - q.getY());
 
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}


Point* jarvis(Point points[], int size){
    
    if (size < 3) throw std::runtime_error("ERROR: Fecho Convexo impossível.");

    Stack<Point> stack = Stack<Point>();

    // Acha o ponto mais a esquerda
    int left = 0;
    for (int i = 1; i < size; i++)
        if (points[i].getX() < points[left].getX())
            left = i;

    int p = left, q;
    do{
        stack.add(points[p]);
        q = (p + 1) % size;
        for (int i = 0; i < size; i++)
            if (orientationJ(points[p], points[i], points[q]) == 2)
                q = i;

        p = q;
    } while (p != left);


    Point* result = new Point[stack.getSize()];

    int count = 0;
    while (!stack.isEmpty())
    {
        Point p = stack.remove();
        result[count] = p;
        //printf("%d %d\n", p.getX(), p.getY());
        count++;
    }

    return result;
}