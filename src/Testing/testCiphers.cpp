//! Unit Tests for MPAGSCipher Ciphers
#include "gtest/gtest.h"

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode,
                const std::string& input, const std::string& expected)
{
    return cipher.applyCipher(input, mode) == expected;
}

TEST(CaesarCipher, Encrypt)
{
    CaesarCipher cc{10};
    EXPECT_TRUE(
        testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
}

TEST(CaesarCipher, Decrypt)
{
    CaesarCipher cc{10};
    EXPECT_TRUE(
        testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
}

TEST(PlayfairCipher, Encrypt)
{
    PlayfairCipher cc{"hello"};
    EXPECT_TRUE(
        testCipher(cc, CipherMode::Encrypt,
                   "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING",
                   "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
}

TEST(PlayfairCipher, Decrypt)
{
    PlayfairCipher cc{"hello"};
    EXPECT_TRUE(
        testCipher(cc, CipherMode::Decrypt,
                   "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA",
                   "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}

TEST(VigenereCipher, Encrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_TRUE(
        testCipher(cc, CipherMode::Encrypt,
                   "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES",
                   "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ"));
}

TEST(VigenereCipher, Decrypt)
{
    VigenereCipher cc{"hello"};
    EXPECT_TRUE(
        testCipher(cc, CipherMode::Decrypt,
                   "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ",
                   "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES"));
}