/*
 * Copyright (C) 2017 - 2024, Stephan Mueller <smueller@chronox.de>
 *
 * License: see LICENSE file in root directory
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
 * WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _CIPHER_DEFINITIONS_H
#define _CIPHER_DEFINITIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * Note: To perform a match between two cipher definitions, use
 *	 convert_cipher_match().
 *
 * Note 2: To verify whether one cipher definition is a subset of another
 *	   cipher definition (i.e one cipher definition contains the other
 *	   cipher definition), use convert_cipher_contains().
 */

#define ACVP_CIPHERDEF		0x0000ffffffffffffULL
#define ACVP_CIPHERTYPE		0xffff000000000000ULL

#define ACVP_CIPHERTYPE_AES	0x0001000000000000ULL
#define ACVP_CIPHERTYPE_TDES	0x0002000000000000ULL
#define ACVP_CIPHERTYPE_AEAD	0x0004000000000000ULL
#define ACVP_CIPHERTYPE_HASH	0x0008000000000000ULL
#define ACVP_CIPHERTYPE_HMAC	0x0010000000000000ULL
#define ACVP_CIPHERTYPE_CMAC	0x0020000000000000ULL
#define ACVP_CIPHERTYPE_ECC	0x0040000000000000ULL
#define ACVP_CIPHERTYPE_DRBG	0x0080000000000000ULL
#define ACVP_CIPHERTYPE_DOMAIN	0x0100000000000000ULL
#define ACVP_CIPHERTYPE_KDF	0x0200000000000000ULL
#define ACVP_CIPHERTYPE_AUX	0x0400000000000000ULL
#define ACVP_CIPHERTYPE_XOF	0x0800000000000000ULL
#define ACVP_CIPHERTYPE_KAS	0x1000000000000000ULL
#define ACVP_CIPHERTYPE_KMAC	0x2000000000000000ULL

/* AES */
#define ACVP_ECB		(ACVP_CIPHERTYPE_AES  | 0x0000000000000001ULL)
#define ACVP_CBC		(ACVP_CIPHERTYPE_AES  | 0x0000000000000002ULL)
#define ACVP_XTS		(ACVP_CIPHERTYPE_AES  | 0x0000000000000003ULL)
#define ACVP_OFB		(ACVP_CIPHERTYPE_AES  | 0x0000000000000004ULL)
#define ACVP_CFB1		(ACVP_CIPHERTYPE_AES  | 0x0000000000000005ULL)
#define ACVP_CFB8		(ACVP_CIPHERTYPE_AES  | 0x0000000000000006ULL)
#define ACVP_CFB128		(ACVP_CIPHERTYPE_AES  | 0x0000000000000007ULL)
#define ACVP_KW			(ACVP_CIPHERTYPE_AES  | 0x0000000000000008ULL)
#define ACVP_KWP		(ACVP_CIPHERTYPE_AES  | 0x0000000000000009ULL)
#define ACVP_CTR		(ACVP_CIPHERTYPE_AES  | 0x000000000000000aULL)
#define ACVP_AES128		(ACVP_CIPHERTYPE_AES  | 0x000000000000000bULL)	/* only used for DRBG */
#define ACVP_AES192		(ACVP_CIPHERTYPE_AES  | 0x000000000000000cULL)	/* only used for DRBG */
#define ACVP_AES256		(ACVP_CIPHERTYPE_AES  | 0x000000000000000dULL)	/* only used for DRBG */
#define ACVP_CBC_CS1		(ACVP_CIPHERTYPE_AES  | 0x000000000000000eULL)
#define ACVP_CBC_CS2		(ACVP_CIPHERTYPE_AES  | 0x0000000000000010ULL)
#define ACVP_CBC_CS3		(ACVP_CIPHERTYPE_AES  | 0x0000000000000020ULL)
#define ACVP_AESMASK		(ACVP_CIPHERTYPE_AES  | 0x00000000000000ffULL)

/* KMAC */
#define ACVP_KMAC128		(ACVP_CIPHERTYPE_KMAC  | 0x0000000000000001ULL)
#define ACVP_KMAC256		(ACVP_CIPHERTYPE_KMAC  | 0x0000000000000002ULL)
#define ACVP_KMACMASK		(ACVP_CIPHERTYPE_KMAC  | 0x0000000000000003ULL)

/* TDES */
#define ACVP_TDESECB		(ACVP_CIPHERTYPE_TDES | 0x0000000000000100ULL)
#define ACVP_TDESCBC		(ACVP_CIPHERTYPE_TDES | 0x0000000000000200ULL)
#define ACVP_TDESOFB		(ACVP_CIPHERTYPE_TDES | 0x0000000000000300ULL)
#define ACVP_TDESCFB1		(ACVP_CIPHERTYPE_TDES | 0x0000000000000400ULL)
#define ACVP_TDESCFB8		(ACVP_CIPHERTYPE_TDES | 0x0000000000000500ULL)
#define ACVP_TDESCFB64		(ACVP_CIPHERTYPE_TDES | 0x0000000000000600ULL)
#define ACVP_TDESCTR		(ACVP_CIPHERTYPE_TDES | 0x0000000000000700ULL)
#define ACVP_TDESKW		(ACVP_CIPHERTYPE_TDES | 0x0000000000000800ULL)
#define ACVP_TDESMASK		(ACVP_CIPHERTYPE_TDES | 0x0000000000000f00ULL)

#define ACVP_SYMMASK		(ACVP_AESMASK | ACVP_TDESMASK)

/* parser_aead.c requires the ability of ORing these flags */
#define ACVP_GCM 		(ACVP_CIPHERTYPE_AEAD | 0x0000000000001000ULL)
#define ACVP_CCM 		(ACVP_CIPHERTYPE_AEAD | 0x0000000000002000ULL)
#define ACVP_GCMSIV		(ACVP_CIPHERTYPE_AEAD | 0x0000000000004000ULL)
#define ACVP_GMAC		(ACVP_CIPHERTYPE_AEAD | 0x0000000000008000ULL)
#define ACVP_AEADMASK		(ACVP_CIPHERTYPE_AEAD | 0x000000000000f000ULL)

#define ACVP_AESCMAC 		(ACVP_CIPHERTYPE_CMAC | 0x0000000000010000ULL)
#define ACVP_TDESCMAC		(ACVP_CIPHERTYPE_CMAC | 0x0000000000020000ULL)
#define ACVP_CMACMASK		(ACVP_CIPHERTYPE_CMAC | 0x0000000000030000ULL)
#define ACVP_HMACSHA1 		(ACVP_CIPHERTYPE_HMAC | 0x0000000000010000ULL)
#define ACVP_HMACSHA2_224 	(ACVP_CIPHERTYPE_HMAC | 0x0000000000020000ULL)
#define ACVP_HMACSHA2_256 	(ACVP_CIPHERTYPE_HMAC | 0x0000000000030000ULL)
#define ACVP_HMACSHA2_384 	(ACVP_CIPHERTYPE_HMAC | 0x0000000000040000ULL)
#define ACVP_HMACSHA2_512	(ACVP_CIPHERTYPE_HMAC | 0x0000000000050000ULL)
#define ACVP_HMACSHA2_512224	(ACVP_CIPHERTYPE_HMAC | 0x0000000000060000ULL)
#define ACVP_HMACSHA2_512256	(ACVP_CIPHERTYPE_HMAC | 0x0000000000070000ULL)
#define ACVP_HMACSHA3_224 	(ACVP_CIPHERTYPE_HMAC | 0x0000000000080000ULL)
#define ACVP_HMACSHA3_256 	(ACVP_CIPHERTYPE_HMAC | 0x0000000000090000ULL)
#define ACVP_HMACSHA3_384 	(ACVP_CIPHERTYPE_HMAC | 0x00000000000a0000ULL)
#define ACVP_HMACSHA3_512	(ACVP_CIPHERTYPE_HMAC | 0x00000000000b0000ULL)
#define ACVP_HMACMASK		(ACVP_CIPHERTYPE_HMAC | 0x00000000000f0000ULL)
#define ACVP_MACMASK		(ACVP_HMACMASK | ACVP_CMACMASK)

#define ACVP_SHA1 		(ACVP_CIPHERTYPE_HASH | 0x0000000000010000ULL)
#define ACVP_SHA224 		(ACVP_CIPHERTYPE_HASH | 0x0000000000020000ULL)
#define ACVP_SHA256 		(ACVP_CIPHERTYPE_HASH | 0x0000000000030000ULL)
#define ACVP_SHA384 		(ACVP_CIPHERTYPE_HASH | 0x0000000000040000ULL)
#define ACVP_SHA512 		(ACVP_CIPHERTYPE_HASH | 0x0000000000050000ULL)
#define ACVP_SHA512224		(ACVP_CIPHERTYPE_HASH | 0x0000000000060000ULL)
#define ACVP_SHA512256		(ACVP_CIPHERTYPE_HASH | 0x0000000000070000ULL)
#define ACVP_SHA3_224 		(ACVP_CIPHERTYPE_HASH | 0x0000000000080000ULL)
#define ACVP_SHA3_256 		(ACVP_CIPHERTYPE_HASH | 0x0000000000090000ULL)
#define ACVP_SHA3_384 		(ACVP_CIPHERTYPE_HASH | 0x00000000000a0000ULL)
#define ACVP_SHA3_512 		(ACVP_CIPHERTYPE_HASH | 0x00000000000b0000ULL)
#define ACVP_HASHMASK		(ACVP_CIPHERTYPE_HASH | 0x00000000000f0000ULL)

/* cipher & ACVP_SHAKEMASK must exclude any ACVP_HASHMASK */
#define ACVP_SHAKE128		(ACVP_CIPHERTYPE_XOF  | 0x0000000000100000ULL)
#define ACVP_SHAKE256		(ACVP_CIPHERTYPE_XOF  | 0x0000000000200000ULL)
#define ACVP_SHAKEMASK		(ACVP_CIPHERTYPE_XOF  | 0x0000000000300000ULL)
#define ACVP_CSHAKE128		(ACVP_CIPHERTYPE_XOF  | 0x0000000000400000ULL)
#define ACVP_CSHAKE256		(ACVP_CIPHERTYPE_XOF  | 0x0000000000800000ULL)
#define ACVP_CSHAKEMASK		(ACVP_CIPHERTYPE_XOF  | 0x0000000000c00000ULL)

/* Curves and hashes must be allowed to be XORed (DH) */
#define ACVP_NISTP224		(ACVP_CIPHERTYPE_ECC  | 0x0000000001000000ULL)
#define ACVP_NISTP256		(ACVP_CIPHERTYPE_ECC  | 0x0000000002000000ULL)
#define ACVP_NISTP384		(ACVP_CIPHERTYPE_ECC  | 0x0000000003000000ULL)
#define ACVP_NISTP521		(ACVP_CIPHERTYPE_ECC  | 0x0000000004000000ULL)
#define ACVP_NISTK233		(ACVP_CIPHERTYPE_ECC  | 0x0000000005000000ULL)
#define ACVP_NISTK283		(ACVP_CIPHERTYPE_ECC  | 0x0000000006000000ULL)
#define ACVP_NISTK409		(ACVP_CIPHERTYPE_ECC  | 0x0000000007000000ULL)
#define ACVP_NISTK571		(ACVP_CIPHERTYPE_ECC  | 0x0000000008000000ULL)
#define ACVP_NISTB233		(ACVP_CIPHERTYPE_ECC  | 0x0000000009000000ULL)
#define ACVP_NISTB283		(ACVP_CIPHERTYPE_ECC  | 0x000000000a000000ULL)
#define ACVP_NISTB409		(ACVP_CIPHERTYPE_ECC  | 0x000000000b000000ULL)
#define ACVP_NISTB571		(ACVP_CIPHERTYPE_ECC  | 0x000000000c000000ULL)
#define ACVP_ED25519		(ACVP_CIPHERTYPE_ECC  | 0x000000000d000000ULL)
#define ACVP_ED448		(ACVP_CIPHERTYPE_ECC  | 0x000000000e000000ULL)
#define ACVP_NISTP192		(ACVP_CIPHERTYPE_ECC  | 0x000000000f000000ULL)
#define ACVP_NISTK163		(ACVP_CIPHERTYPE_ECC  | 0x0000000010000000ULL)
#define ACVP_NISTB163		(ACVP_CIPHERTYPE_ECC  | 0x0000000020000000ULL)
#define ACVP_CURVEMASK		(ACVP_CIPHERTYPE_ECC  | 0x00000000ff000000ULL)

/* Those are ORed with hashes */
#define ACVP_ECDH 		(ACVP_CIPHERTYPE_AUX  | 0x0000000000000001ULL)
#define ACVP_RSA		(ACVP_CIPHERTYPE_AUX  | 0x0000000000000002ULL)
#define ACVP_ECDSA		(ACVP_CIPHERTYPE_AUX  | 0x0000000000000003ULL)
#define ACVP_DSA		(ACVP_CIPHERTYPE_AUX  | 0x0000000000000004ULL)
#define ACVP_DH			(ACVP_CIPHERTYPE_AUX  | 0x0000000000000005ULL)
#define ACVP_EDDSA		(ACVP_CIPHERTYPE_AUX  | 0x0000000000000006ULL)
#define ACVP_ECDH_ED		(ACVP_CIPHERTYPE_AUX  | 0x0000000000000007ULL)
#define ACVP_KAS_FFC_R3_SSC	(ACVP_CIPHERTYPE_AUX  | 0x0000000000000008ULL)
#define ACVP_KAS_ECC_R3_SSC	(ACVP_CIPHERTYPE_AUX  | 0x0000000000000009ULL)
#define ACVP_SAFEPRIMES		(ACVP_CIPHERTYPE_AUX  | 0x000000000000000fULL)

#define ACVP_LMS		(ACVP_CIPHERTYPE_AUX  | 0x000000000000000aULL)

/* Those are ORed with hashes, MACs and symmetric ciphers */
#define ACVP_DRBGCTR		(ACVP_CIPHERTYPE_DRBG | 0x0000000001000000ULL)
#define ACVP_DRBGHMAC		(ACVP_CIPHERTYPE_DRBG | 0x0000000002000000ULL)
#define ACVP_DRBGHASH		(ACVP_CIPHERTYPE_DRBG | 0x0000000004000000ULL)
#define ACVP_DRBGMASK		(ACVP_CIPHERTYPE_DRBG | 0x000000000f000000ULL)

#define ACVP_DH_MODP_2048	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000001ULL)
#define ACVP_DH_MODP_3072	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000002ULL)
#define ACVP_DH_MODP_4096	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000004ULL)
#define ACVP_DH_MODP_6144	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000008ULL)
#define ACVP_DH_MODP_8192	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000010ULL)
#define ACVP_DH_FFDHE_2048	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000020ULL)
#define ACVP_DH_FFDHE_3072	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000040ULL)
#define ACVP_DH_FFDHE_4096	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000080ULL)
#define ACVP_DH_FFDHE_6144	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000100ULL)
#define ACVP_DH_FFDHE_8192	(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000200ULL)
#define ACVP_DH_FB		(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000400ULL)
#define ACVP_DH_FC		(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000000800ULL)
#define ACVP_DH2048224 		(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000001000ULL)
#define ACVP_DH2048256		(ACVP_CIPHERTYPE_DOMAIN | 0x0000000000002000ULL)
#define ACVP_DH_DOMAIN_MASK	(ACVP_CIPHERTYPE_DOMAIN | 0x000000000000ffffULL)

#define ACVP_KDF_COMPONENT	(ACVP_CIPHERTYPE_KDF  | 0x0000000000000001ULL)
#define ACVP_KDF_800_108	(ACVP_CIPHERTYPE_KDF  | 0x0000000000000002ULL)
#define ACVP_KDA		(ACVP_CIPHERTYPE_KDF  | 0x0000000000000004ULL)
#define ACVP_PBKDF		(ACVP_CIPHERTYPE_KDF  | 0x0000000000000008ULL)
#define ACVP_KDF_MASK		(ACVP_CIPHERTYPE_KDF  | 0x000000000000000fULL)

#define ACVP_KDF_108_DOUBLE_PIPELINE					\
				(ACVP_CIPHERTYPE_KDF  | 0x0000000000000010ULL)
#define ACVP_KDF_108_FEEDBACK	(ACVP_CIPHERTYPE_KDF  | 0x0000000000000020ULL)
#define ACVP_KDF_108_COUNTER	(ACVP_CIPHERTYPE_KDF  | 0x0000000000000040ULL)
#define ACVP_KDF_108_AFTER_FIXED					\
				(ACVP_CIPHERTYPE_KDF  | 0x0000000000000100ULL)
#define ACVP_KDF_108_BEFORE_FIXED					\
				(ACVP_CIPHERTYPE_KDF  | 0x0000000000000200ULL)
#define ACVP_KDF_108_MIDDLE_FIXED					\
				(ACVP_CIPHERTYPE_KDF  | 0x0000000000000400ULL)
#define ACVP_KDF_108_BEFORE_ITERATOR					\
				(ACVP_CIPHERTYPE_KDF  | 0x0000000000000800ULL)

#define ACVP_KDF_TLS13		(ACVP_CIPHERTYPE_KDF  | 0x0000000000001000ULL)
#define ACVP_KDF_TLS12		(ACVP_CIPHERTYPE_KDF  | 0x0000000000002000ULL)

#define ACVP_KDA_HKDF		(ACVP_CIPHERTYPE_KDF  | 0x0000000000010000ULL)
#define ACVP_KDA_ONESTEP	(ACVP_CIPHERTYPE_KDF  | 0x0000000000020000ULL)
#define ACVP_KDA_ONESTEP_NO_COUNTER					\
				(ACVP_CIPHERTYPE_KDF  | 0x0000000000040000ULL)
#define ACVP_KDA_TWOSTEP	(ACVP_CIPHERTYPE_KDF  | 0x0000000000080000ULL)

/* SP800-56B rev 2 */
#define ACVP_KTS_IFC		(ACVP_CIPHERTYPE_KAS | 0x0000000000000001ULL)
#define ACVP_KAS_IFC_SSC	(ACVP_CIPHERTYPE_KAS | 0x0000000000000002ULL)
#define ACVP_KTS_SCHEMA_OAEP_BASIC					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000010ULL)
#define ACVP_KTS_SCHEMA_OAEP_PARTY_V_CONF				\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000020ULL)
#define ACVP_KAS1_SCHEMA_BASIC						\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000040ULL)
#define ACVP_KAS1_SCHEMA_PARTY_V_CONF					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000080ULL)
#define ACVP_KAS2_SCHEMA_BASIC						\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000100ULL)
#define ACVP_KAS2_SCHEMA_BILATERAL_CONF					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000200ULL)
#define ACVP_KAS2_SCHEMA_PARTY_U_CONF					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000400ULL)
#define ACVP_KAS2_SCHEMA_PARTY_V_CONF					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000800ULL)
#define ACVP_KTS_KAS_SCHEMA_MASK					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000000ff0ULL)

#define ACVP_KAS_KEYGEN_RSAKPG1_BASIC					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000001000ULL)
#define ACVP_KAS_KEYGEN_RSAKPG1_PRIME_FACTOR				\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000002000ULL)
#define ACVP_KAS_KEYGEN_RSAKPG1_CRT					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000004000ULL)
#define ACVP_KAS_KEYGEN_RSAKPG2_BASIC					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000008000ULL)
#define ACVP_KAS_KEYGEN_RSAKPG2_PRIME_FACTOR				\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000010000ULL)
#define ACVP_KAS_KEYGEN_RSAKPG2_CRT					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000020000ULL)
#define ACVP_KAS_ENCODING_NONE						\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000040000ULL)
#define ACVP_KAS_ENCODING_CONCATENATION					\
				(ACVP_CIPHERTYPE_KAS | 0x0000000000080000ULL)

#define ACVP_UNKNOWN		0x0000000000000000ULL

#ifdef __cplusplus
}
#endif

#endif /* _CIPHER_DEFINITIONS_H */
