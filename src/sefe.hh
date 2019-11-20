namespace sefe_pkg
{
#include "sefe_fields.hh"
#include <deque>
#include <iostream>
using namespace std;

//deque<sefe_fields*> sefe_queue;
// Tanushree: Sefe class which contains all the sefe entries in a queue. Manipulated inside lsq files.
//
class sefe
{
	public:
        deque<sefe_fields*> sefe_queue;

//	static bool flag;
//	static sefe* my_sefe_ptr;

//	sefe()
//	{
//		flag=0;
//		my_sefe_ptr=NULL;
//	}

	void print_sefe()
	{
		deque<sefe_fields*>::iterator it;
		for(it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			cout<<"Sefe_entry["<<(*it)->seq_num<<"], req_addr = 0x"<<std::hex<<(*it)->req_addr<<", l1_evict_addr_valid = "<<(*it)->l1_evict_addr_valid<<", l1_evict_addr = 0x"<<(*it)->l1_evict_addr<<endl;
		}
	}

	sefe_fields* create_sefe_fields(int seq_num)
	{
		sefe_fields* temp = new sefe_fields;
		temp->seq_num             = seq_num;
		temp->l1_evict_addr_valid = 0;
		temp->l1_evict_addr       = 0;
		temp->req_addr            = 0;

		return temp;
	}

	void set_req_addr(int seq_num, Addr address)
	{
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
				(*it)->req_addr = address;
		}
	}

	void set_evict_addr(int seq_num, bool l1_evict_addr_valid, Addr address)
	{
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
			{
				(*it)->l1_evict_addr_valid = l1_evict_addr_valid;
				(*it)->l1_evict_addr = address;
			}
		}
	}

	void set_req_addr_pkt(int seq_num, PacketPtr req_addr_pkt)
	{
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
				(*it)->req_addr_pkt = req_addr_pkt;
		}
	}

	Addr get_req_addr(int seq_num)
	{
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
				return ((*it)->req_addr);
		}
		return 0;
	}

	bool get_evict_addr_valid(int seq_num)
	{	
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
				return ((*it)->l1_evict_addr_valid);
		}
		return NULL;
	}

	Addr get_evict_addr(int seq_num)
	{	
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
				return ((*it)->l1_evict_addr);
		}
		return 0;
	}
	
	PacketPtr get_req_addr_pkt(int seq_num)
	{
		for(auto it=sefe_queue.begin(); it!=sefe_queue.end(); ++it)
		{
			if(seq_num == (*it)->seq_num)
				return ((*it)->req_addr_pkt);
		}
		return 0;
	}

	void push_back_sefe(sefe_fields* temp)
	{
		sefe_queue.push_back(temp);
	}

	sefe_fields* pop_back_sefe()
	{
		sefe_fields* temp;
		temp = sefe_queue.back();
		sefe_queue.pop_back();
		return temp;
	}

	static sefe* create_sefe()
	{
		static bool flag=0;
		static sefe* my_sefe_ptr=NULL;

		if(flag==0)
		{
			sefe* temp = new sefe;
			my_sefe_ptr = temp;
			flag = 1;
		}
		return my_sefe_ptr;
	}
};

//bool sefe::flag=0;
//sefe* sefe::my_sefe_ptr=NULL;

}
