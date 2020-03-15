#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class client

{
protected:
    void sha256_hash_string(unsigned char hash[SHA256_DIGEST_LENGTH], char outputBuffer[65]);
    void sha256_string(char *string, char outputBuffer[65]);

public:
    void ibchullyeog();

    void
    sha256_hash_string(unsigned char hash[SHA256_DIGEST_LENGTH], char outputBuffer[65])
    {
        int i = 0;

        for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
        }

        outputBuffer[64] = 0;
    }

    void sha256_string(char *string, char outputBuffer[65])
    {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, string, strlen(string));
        SHA256_Final(hash, &sha256);
        int i = 0;
        for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
        }
        outputBuffer[64] = 0;
    }

    int sha256_file(char *path, char outputBuffer[65])
    {
        FILE *file = fopen(path, "rb");
        if (!file)
            return -534;

        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        const int bufSize = 32768;
        unsigned char *buffer = malloc(bufSize);
        int bytesRead = 0;
        if (!buffer)
            return ENOMEM;
        while ((bytesRead = fread(buffer, 1, bufSize, file)))
        {
            SHA256_Update(&sha256, buffer, bytesRead);
        }
        SHA256_Final(hash, &sha256);

        sha256_hash_string(hash, outputBuffer);
        fclose(file);
        free(buffer);
        return 0;
    }

    {

        void ibchullyeog()
            // 파일 읽기 준비
            std::ifstream in("test.txt");
        std::string s;

        while (in)
        {
            getline(in, s);
            std::cout << s << std::endl;
        }

        std::ofstream out("test.txt");
        // 파일 쓰기

        return 0;
    }