def create_string_with_fields(field_dict):
    # Crée une liste vide pour stocker les descriptions des champs
    field_descriptions = []

    # Parcourt le dictionnaire de champs
    for field, info in field_dict.items():
        # Extrait les bits du champ et sa description
        bits = info['bits']
        desc = info['desc']
        
        # Crée la description du champ dans le bon format et l'ajoute à la liste
        field_description = f"{field} {bits}: {desc}"
        field_descriptions.append(field_description)
    
    # Inverse la liste pour correspondre à l'ordre des bits dans le string "-"
    field_descriptions.reverse()
    
    # Crée une chaîne de caractères avec des blocs de 32 "-" séparés par un espace
    result_string = "-" * 32 * len(field_descriptions)
    
    # Remplace les bits par les noms des champs dans la chaîne de caractères
    for field_description in field_descriptions:
        field, bits, _ = field_description.split(' ', 2)
        start_bit, end_bit = bits[1:-1].split(':')
        start_bit = int(start_bit)
        end_bit = int(end_bit)
        length = end_bit - start_bit + 1
        replacement = f"{field: <10}"[:length][::-1]
        result_string = result_string[:start_bit] + replacement + result_string[start_bit + length:]

    return result_string

# Exemple d'utilisation avec le dictionnaire de champs fourni
fields = {
    'SIMM16': {'bits': '15:0', 'desc': 'Signed immediate 16-bit value.'},
    'OP': {'bits': '22:16', 'desc': 'See Opcode table below.'},
    'ENCODING': {'bits': '31:23', 'desc': 'Must be: 10_1111111'}
}

result_string = create_string_with_fields(fields)
print(result_string)