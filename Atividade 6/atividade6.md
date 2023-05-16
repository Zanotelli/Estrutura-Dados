### 1. Avalie qualitativamente o programa a ser caracterizado em termos dos acessos de memória esperados e localidade de referência. Identifique as estruturas de dados e segmentos de código críticos (p.ex., mais custosos)

---
### 2. Elabore o plano de caracterização de localidade de referência, nesse momento indicando as execuções e ferramentas a serem realizadas e porque.

---
### 3. Selecione os parâmetros do programa a ser caracterizado

#### 1) Programa não deve executar por muito ou pouco tempo, mas o suficiente para entender o comportamento do algoritmo.

---
### 4. Execute o código com Cachegrind:

#### 1) valgrind --tool=cachegrind <binário do programa> <parâmetros>

#### 2) cg_annotate cachegrind.out.<número do processo do passo 1>

---
### 5. Execute o código com Callgrind

#### 1) valgrind --tool=callgrind  <binário do programa> <parâmetros>

#### 2) callgrind_annotate callgrind.out.<número do processo do passo 1>

---
### 6. Avalie as saídas do CacheGrind/CallGrind para responder as seguintes perguntas:

#### 1) Quão bem o programa se comporta em termos de memória?

#### 2) Quais estruturas de dados devem serem caracterizadas para melhor entendimento?

#### 3) Quais segmentos de código devem instrumentados para suportar a caracterização?