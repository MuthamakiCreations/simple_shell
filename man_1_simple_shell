.TH SIMPLE_SHELL 1 "28 March 2018" "1.0" "custom man page"
.SH NAME
.B Simple Shell
- command language interpreter
.SH SYNOPSIS
.B Simple Shell
.SH DESCRIPTION
Simple shell is one version of a command language interpreter that executes commands read from the standard input. It's functionality is limited to certain shell builtin functions found in the environmental variable defined by the user
.I PATH.
It does not handle piping, redirection, pattern matching, variable expansions, and more extra functions.
.SS Invocation
An
.I interactive
simple shell can be invoked by typing ./simple_shell. Meanwhile, a
.I non-interactive
simple shell can also be invoked via a pipe (e.g. echo "/bin/ls" | ./simple_shell).
.SS Command Execution
After a command has been split into words, if it results in a simple command and an optional list of arguments, the following actions are taken.
.sp
If the command name contains no slashes, the shell attempts to locate it. If there exists a shell function by that name that function is invoked. If the name does not match a function, the shell searches for it in the list of shell builtins. If a match is found, that builtin is invoked.
.sp
If the name is neither a shell function nor a builtin, and contains no slashes, the simple shell searches each element of the environmental variable PATH for a directory containing an executable file by that name. If the search is unsuccessful, the simple shell prints an error message "Error: File or description not found."
.SS Sample Functions
.sp
echo
.I [arguments]
      prints standard output argument and print newline
.sp
ls
.I [[flags]...[arguments]]
      lists files in current directory according to the flags given by user
.sp
pwd
      prints working directory
.sp
whereis
.I [command]
      prints to standard output directory of the function shell builtin found
.SS Shell Builtin Commands
.sp
cd
      changes directory updates environmental variables OLDPWD and PWD
.sp
env
      prints environmental variables
.sp
exit
      exits shell and returns to user's shell
.sp
setenv
      create empty or modify existing environmental variable in shell session
.sp
unsetenv
      removes existing environmental variable within shell session
.SH EXAMPLE
To
.I invoke
simple shell:
.sp
.RS
(your_terminal)$ ./simple_shell
.RE
.RS
.I $
.RE
.sp
Sample Usage:
.sp
.RS
.I $
echo "This is cool!"
.RE
.RS
.I This is cool!
.RE
.RS
.I $
ls -l /tmp
.RE
.RS
.I total 4
.RE
.RS
.I drwx------ 2 vagrant vagrant 4096 Mar 19 20:22 ssh-xTKqci
.RE
.sp
Leave simple shell and return to terminal:
.sp
.RS
.I $
exit
.RE
.RS
(your_terminal)$
.RE
.SH BUGS
Bugs...
.SH SEE ALSO
.I bash(1), sh(1), ksh(1), csh(1)
.SH AUTHORS
Maxwel and Moses
