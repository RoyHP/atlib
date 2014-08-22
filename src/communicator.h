#ifndef ATLIB_COMMUNICATOR
#define ATLIB_COMMUNICATOR

/*
	Communicator
	Generic functions for communicating with the
*/
namespace atlib {
	class Communicator {
		// Generic communication methods
		void send(char* );
		char** recv();
		void disconnect();
		bool connect(char* port);
	};
}
#endif // ATLIB_COMMUNICATOR
