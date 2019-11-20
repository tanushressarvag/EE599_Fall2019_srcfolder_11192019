// Tanushree class containing entries for one sefe entry
typedef uint64_t Addr;
class sefe_fields
{
	public:
	bool valid;
	bool is_spec;
	int epoc_id;
	int load_id;
	bool l1_hit;
	bool l2_hit;

	bool l1_evict_addr_valid;
	Addr l1_evict_addr;
	Addr req_addr;
	int seq_num;
	PacketPtr req_addr_pkt;
	PacketPtr evict_addr_pkt;
};
