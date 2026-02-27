#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"
#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher class, a pABC for all ciphers
 */

class Cipher {
  public:
    // Set default special member functions
    Cipher() = default;
    Cipher(const Cipher& rhs) = default;
    Cipher& operator=(const Cipher& rhs) = default;
    Cipher& operator=(Cipher&& rhs) = default;
    virtual ~Cipher() = default;

    /**
     * \brief Pure virtual function to apply the cipher to a given text
     *
     * \param input The text to which the cipher should be applied
     * \param mode The mode of the cipher to be applied
     * \return The result of applying the cipher to the input text
     */
    virtual std::string applyCipher(const std::string& input,
                                    const CipherMode mode) const = 0;
};

#endif    // MPAGSCIPHER_CIPHER_HPP