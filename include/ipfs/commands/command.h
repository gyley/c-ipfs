/***
 * The structures to commands
 */

#ifndef __COMMANDS_COMMAND_H__
#define __COMMANDS_COMMAND_H__

#include "argument.h"
#include "request.h"
#include "command_option.h"

struct HelpText {
	char* tagline;
	char* short_description;
	char** synopsis_options_values;

	// optional
	char* usage;
	char* long_description;
	char* options;
	char* subcommands;
	char* synopsis;
};

struct Command {
	struct CommandOption** options;
	int option_count;
	struct Argument** arguments;
	int argument_count;
	int (*pre_run)(struct Request*);
	int (*run)(struct Request*);
	int (*post_run)(struct Request*);
	//struct marshaller** marshallers;
	struct HelpText help_text;

	// a boolean to determine if this is an external
	// binary.
	int external;

	//struct type return_type;
	char** subcommands;
};

// construction/destruction
int init_command(struct Command* cmd);
int uninit_command(struct Command* cmd);

#endif // command.h