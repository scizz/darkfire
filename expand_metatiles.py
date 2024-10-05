import os
import struct

OLD_METATILE_MASK  = 0b0000001111111111
OLD_COLLISION_MASK = 0b0000110000000000
OLD_ELEVATION_MASK = 0b1111000000000000

NEW_COLLISION_MASK = 0b0001
NEW_ELEVATION_MASK = 0b0111

def process_map_data(old_data):
    new_data = []

    for value in old_data:
        metatile_id = value & OLD_METATILE_MASK
        collision = (value & OLD_COLLISION_MASK) >> 10
        elevation = (value & OLD_ELEVATION_MASK) >> 12

        if elevation == 15:
            elevation = 7
        if metatile_id >= 0x200:
            metatile_id += 0x600

        new_value = metatile_id | ((collision & NEW_COLLISION_MASK) << 12) | ((elevation & NEW_ELEVATION_MASK) << 13)
        new_data.append(new_value)

    return new_data

def read_map_bin(file_path):
    with open(file_path, "rb") as f:
        data = f.read()
        return list(struct.unpack("<" + "H" * (len(data) // 2), data))

def write_map_bin(file_path, new_data):
    with open(file_path, "wb") as f:
        f.write(struct.pack("<" + "H" * len(new_data), *new_data))

def find_map_files(base_path="data/layouts"):
    map_files = []
    for root, dirs, files in os.walk(base_path):
        for file in files:
            if file == "map.bin":
                map_files.append(os.path.join(root, file))
    return map_files

def process_all_maps(base_path="data/layouts"):
    map_files = find_map_files(base_path)
    for map_file in map_files:
        print(f"Processing {map_file}...")
        old_data = read_map_bin(map_file)
        new_data = process_map_data(old_data)
        write_map_bin(map_file, new_data)

if __name__ == "__main__":
    process_all_maps()