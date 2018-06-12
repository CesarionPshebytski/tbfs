#define LOGFILE	"mount.log"

struct tb_state {
      FILE *logfile;
      char *rootdir;
  };
#define TB_DATA ((struct tb_state *) fuse_get_context()->private_data)

#define log_struct(st, field, format, typecast) \
  log_msg("    " #field " = " #format "\n", typecast st->field)
