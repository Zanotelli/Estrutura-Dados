class Teste
{
    public:
        Teste();
        ~Teste();
        void TestaInt(const char*, int, int);
        void TestaThrow(const char*, void (*f)(int), int);
    private:
        int count_teste;
        int count_sucessos;
        int count_falhas;
        void AumentaCount();
};