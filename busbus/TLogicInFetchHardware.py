NUM_SUBARRAYS = 4

def t_logic_row_addresses(pc_subarray_index, base_row_addr):
    """
    Simulate RS/6000 T-logic row address generation.
    
    pc_subarray_index: which subarray the PC points to (0..3)
    base_row_addr: row address for the subarray containing the PC
    """
    row_addrs = []
    for sub in range(NUM_SUBARRAYS):
        # If subarray index is before the PC's starting subarray,
        # it needs to fetch from the *next* row
        if sub < pc_subarray_index:
            row_addrs.append(base_row_addr + 1)
        else:
            row_addrs.append(base_row_addr)
    return row_addrs

# Example: PC starts in subarray 2, row address 100
print(t_logic_row_addresses(pc_subarray_index=2, base_row_addr=100))
# Output: [101, 101, 100, 100]
# Meaning: subarrays 0 & 1 fetch from row 101, subarrays 2 & 3 from row 100