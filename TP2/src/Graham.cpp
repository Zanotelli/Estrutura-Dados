#include "../include/Graham.h"

// A utility function to swap two points
void swap(Point& p1, Point& p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

Point nextToTop(Stack<Point>& S)
{
    Point p = S.look();
    S.remove();
    Point res = S.look();
    S.add(p);
    return res;
}


Fecho graham(Point* points, int size, char sort){

    if (size < 3) throw std::runtime_error("ERROR: Fecho Convexo impossível.");

    // Acha o ponto com Y mais baixo
    int ymin = points[0].getY(), min = 0;
    for (int i = 1; i < size; i++) {
        int y = points[i].getY();
 
        if ((y < ymin) || (ymin == y && points[i].getX() < points[min].getX()))
            ymin = points[i].getY(), min = i;
    }
    
    // Coloca esse ponto como 1º
    swap(points[0], points[min]);

    // Ordena os pontos
    if(sort == 'M'){
        mergeSort(points, size);
    } else if(sort == 'I'){
        insertionSort(points, size, points[0]);
    } else if(sort == 'B'){
        //bucketSort(&points[1], size, points[0]);
    }

    Stack<Point> S = Stack<Point>();
    S.add(points[0]);
    S.add(points[1]);
    S.add(points[2]);
 
    // Process remaining n-3 points
	try{
        for (int i = 3; i < size; i++) {
            while (orientation(nextToTop(S), S.look(), points[i]) != 2)
                S.remove();
            
            S.add(points[i]);
        }
    }catch(const std::exception & e){
		throw std::runtime_error(e.what());
	}

    Fecho hull = Fecho();
    Point first = S.look();
    Point p1;
    Point p2;

    S.invert();
    while (!S.isEmpty())
    {
        p1 = S.remove();
        if(!S.isEmpty()) 
            p2 = S.look();
        else
            p2 = first;

        Line* line = new Line(new Point(p1.getX(), p1.getY()), 
                                new Point(p2.getX(), p2.getY()));
        /* line->print();
        printf("\n"); */
        hull.add(line);
    }

    return hull;

}