def parse_string(input_str):
    TYPE_SUFFIX = ['b512', 'b256', 'b128', 'b64', 'b32', 'b16', 'b8', 'u64', 'u32', 'u16', 'u8', 'i64', 'i32', 'i16', 'i8', 'f64', 'f32', 'f16', 'b16', 'u16', 'i16', 'f16']
    ENCODING_SUFFIX = ['e32', 'e64', 'sdwa', 'e64_dpp', 'dpp']

    base_str = input_str
    type_suffix = None
    encoding_suffix = None

    for enc_suffix in ENCODING_SUFFIX:
        if input_str.endswith(enc_suffix):
            encoding_suffix = enc_suffix
            base_str = input_str[:-len(enc_suffix)-1]
            break

    for type_suf in TYPE_SUFFIX:
        if base_str.endswith(type_suf):
            type_suffix = type_suf
            base_str = base_str[:-len(type_suf)-1]
            break

    return base_str, type_suffix, encoding_suffix

# Exemple d'utilisation
print(parse_string('ABC'))
print(parse_string('ABC_b256'))
print(parse_string('ABC_b256_dpp'))
print(parse_string('ABC_dpp'))
print(parse_string('ABC_b256_e64'))
print(parse_string('ABC_b256_e64_d'))
print(parse_string('_ABC_e32'))
