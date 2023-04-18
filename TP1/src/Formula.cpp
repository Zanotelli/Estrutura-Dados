#include "../include/Formula.h"


// CONSTRUCTOR

Formula::Formula(const char * formula)
{
    stack = Pilha();
    queue = Fila();
    postFix = isPostFix(formula) ? formula : convert2PostFix(formula);
    inFix = isInFix(formula) ? formula : convert2InFix(formula);
}


// PUBLIC

const char * Formula::GetIn()
{
    return inFix;
}

const char * Formula::GetPost()
{
    return postFix;
}


// PRIVATE

const char * Formula::convert2PostFix(const char * formula)
{
    
}

const char * Formula::convert2InFix(const char * formula)
{
    
}

bool Formula::isPostFix(const char * formula)
{

}

bool Formula::isInFix(const char * formula)
{
    
}