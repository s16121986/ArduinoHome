class Command{
public:
	Command(uint8_t target, uint8_t action, uint8_t data) {
		this->target = target;
		this->action = action;
		this->data = data;
	}
	bool operator==( uint8_t target ) { return target == this->target; }
	
	uint8_t target;
	uint8_t action;
	uint8_t data;
};