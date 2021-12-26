typedef struct ponto Ponto;

Ponto *criaPonto(float x, float y);
void liberaPonto(Ponto *p);
void acessaPonto(Ponto *p);
void atribuiPonto(Ponto *p, float x, float y);
float distanciaPonto(Ponto *p1, Ponto *p2);
