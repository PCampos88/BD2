# BD2

A aplicação considerada será um censo global fictício de seis (6) bilhões de pessoas. Os dados considerados são: sexo (F/M), idade (0-127), renda mensal (0- 1023) * US$1000/ano, escolaridade (0-3), idioma (0-4095), país (0-255), localizador (coordenadas geográficas da pessoa responsável pelo censo). Os dados serão gerados aleatoriamente respeitando os intervalos definidos.

### Sistema de arquivos binários
O sistema de arquivos binários é basicamente o que vocês tiveram de utilizar nas disciplinas de AEDS. É criado um programa em C /C++/Java/etc que define uma estrutura em registro utilizando de preferência campos binários e inteiros. Por exemplo, sexo não será um campo char que registra ‘F’ e ‘M’, mas sim um bit 0 ou 1 (o qual será interpretado pelo programa como feminino ou masculino). O banco de dados pode ser um arquivo binário com todos os registros armazenados da seguinte maneir a: 1 bit sexo, 7-bits idade, 10-bits renda, 2-bits escolaridade, 12 -bits idioma, 8-bits país, 24-bits localizador. O processo de consulta será igualmente através do programa C/C++/Java, o qual pode apresentar um menu com as consultas fixas que podem ser realizadas.

### Banco de dados relacional
O banco de dados relacional será definido utilizando uma modelagem simples com todos os dados em uma única tabela – seguindo o estilo do arquivo binário cuja interpretação dos dados é realizada pelo programa que o utiliza (até para permitir uma comparação mais justa). O processo de consulta será realizado via SQL através da interface do próprio SGBD. Sugere-se utilizar os SGBDs free MySQL ou PostgreSQL.
