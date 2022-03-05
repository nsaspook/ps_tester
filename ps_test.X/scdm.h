/* 
 * File:   scdm.h
 * Author: root
 *
 * Created on March 4, 2022, 9:05 PM
 */

#ifndef SCDM_H
#define	SCDM_H

#ifdef	__cplusplus
extern "C" {
#endif

	/*
	 * adapted from original code link: http://pcarduino.blogspot.com/2014/01/simple-serial-port-command-line.html
	 * refactored and adapted for embedded xc apps
	 */
	/*
	 * serial port command parser
	 */
#define CLI_CMD_BUFFER_SIZE 128

	typedef struct _t_cmd {
		const char *cmd;
		void (*fh)(void*);
	} t_cmd;

	typedef struct _t_cli_ctx {
		t_cmd *cmds;
		char cmd[CLI_CMD_BUFFER_SIZE];
		uint8_t cpos;
	} t_cli_ctx;

#define CLI_IO_INPUT(__data) \
	linux_getc(__data)

#define CLI_IO_OUTPUT(__data, __len) \
	linux_putc(__data, __len)

#define KEY_CODE_BACKSPACE	0x7f
#define KEY_CODE_DELETE		0x7e
#define KEY_CODE_ENTER		'\r'
#define KEY_CODE_ESCAPE		0x1b

#define POSINC(__x) (((__x) < (CLI_CMD_BUFFER_SIZE - 1)) ? (__x + 1) : (__x))
#define POSDEC(__x) ((__x) ? ((__x) - 1) : 0)

	typedef enum _t_cmd_status {
		E_CMD_OK = 0,
		E_CMD_NOT_FOUND,
		E_CMD_TOO_SHORT,
		E_CMD_EMPTY
	} t_cmd_status;

	/*
	 * command execute functions
	 * prototypes
	 */
	void fh_hw(void *a_data);
	void fh_hi(void *a_data);
	void fh_ho(void *a_data);

	/*
	 * command parser functions
	 */
	void scmd_init(void);
	void cli_read(t_cli_ctx *);


#ifdef	__cplusplus
}
#endif

#endif	/* SCDM_H */

