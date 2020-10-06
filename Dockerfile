FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN g++ test.cpp -o lexical
RUN chmod +x lexical
