# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples
export PATH="$PATH:/soft/tools/linux"
# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
    # We have color support; assume it's compliant with Ecma-48
    # (ISO/IEC-6429). (Lack of such support is extremely rare, and such
    # a case would tend to support setf rather than setaf.)
    color_prompt=yes
    else
    color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

alias 51='. /soft/tools/linux.env 5.1R1'
alias 734r01='. /soft/tools/linux.env 7.3.4.R01'
alias 734r02='. /soft/tools/linux.env 7.3.4.R02'
alias 7xx='. /soft/tools/linux.env 7.X.X.R01'
alias 7m='. /soft/tools/linux.env 7.X.X.M'
alias 811r01='. /soft/tools/linux.env 8.1.1.R01'
alias 821c='. /soft/tools/linux.env 8.2.1.C'
alias 821r01='. /soft/tools/linux.env 8.2.1.R01'
alias 831r01='. /soft/tools/linux.env 8.3.1.R01'
alias 831r02='. /soft/tools/linux.env 8.3.1.R02'
alias 841r01='. /soft/tools/linux.env 8.4.1.R01'
alias 841r02='. /soft/tools/linux.env 8.4.1.R02'
alias 841r03='. /soft/tools/linux.env 8.4.1.R03'
alias 85r01='. /soft/tools/linux.env 8.5.R01'
alias 85r02='. /soft/tools/linux.env 8.5.R02'
alias 85r03='. /soft/tools/linux.env 8.5.R03'
alias 85r04='. /soft/tools/linux.env 8.5.R04'
alias 86c='. /soft/tools/linux.env 8.6.C'
alias 86r01='. /soft/tools/linux.env 8.6.R01'
alias 86r02='. /soft/tools/linux.env 8.6.R02'
alias 87r01='. /soft/tools/linux.env 8.7.R01'
alias 87r02='. /soft/tools/linux.env 8.7.R02'
alias 87r03='. /soft/tools/linux.env 8.7.R03'
alias 88r01='. /soft/tools/linux.env 8.8.R01'
alias 86c='.  /soft/tools/linux.env 8.6.C'
alias cli='cd $OS_DEV_DIR/sw/management/cli'
alias con='console -M porto -p 782 -E'
alias cona='con -u | grep 6860 | grep up | grep none'
alias conb='con -u | grep 6900 | grep up | grep none'
alias ethernet='cd $OS_DEV_DIR/sw/drivers/ethernet'
alias header='cd $OS_DEV_DIR/sw/h'
alias images='cd $OS_DEV_DIR/sw/images'
alias ll='ls -laF'
alias mall='make -j20'
alias medora='make buildALU=medora -j20'
alias medora_sim='make buildALU=medora_sim -j20'
alias medora_sim64='make buildALU=medora_sim64 -j20'
alias mibs='cd $OS_DEV_DIR/sw/management/snmp/mibs'
alias mrushmore='make buildALU=rushmore -j20'
alias mshasta='make buildALU=shasta -j20'
alias mtor='make buildALU=tor -j20'
alias mnandi='make buildALU=nandi -j20'
alias nandi_sim='make buildALU=nandi_sim -j20'
alias ntruong='/soft/tools/p4 sync && make buildALU=shasta -j20'
alias clean='make -j30 clean'
alias p4a='/soft/tools/p4 add'
alias p4e='/soft/tools/p4 edit'
alias p4o='/soft/tools/p4 opened'
alias p4r='/soft/tools/p4 revert'
alias p4rs='/soft/tools/p4 resolve'
alias p4s='/soft/tools/p4 sync'
alias rbt='$HOME/software/bin/rbt'
alias scp_image='scp /home/ntruong/Uos.img admin@10.255.75.77:/flash/working'
alias snmp='cd $OS_DEV_DIR/sw/management/snmp'
alias sw='cd $OS_DEV_DIR/sw'
alias vi='/usr/bin/vim -p'
alias web='cd $OS_DEV_DIR/sw/management/web'
alias lp='ls -l ~/PERFORCE'

alias mshasta_n='make buildALU=shasta_n -j20'
alias mallnosim='mshasta;mshasta_n;myukon;mtor;mmedora;mnandi;maravalli;'
alias myukon='make buildALU=yukon -j20'
alias mmedora='make buildALU=medora -j20'
alias maravalli='make buildALU=aravalli -j20'
alias sim='cd cd $OS_DEV_DIR/engr/simulation/simenv/scripts'
alias ssh135='ssh thaib@135.250.137.37'
alias sim2='cd $OS_DEV_DIR/simulation/simenv/scripts/;sim.py -t ../../../../../7.X.X.M-tdao0751-MPLSCLI/engr/pal/schema/vc_sim/9900/mpls2.schema'
alias sim3='cd $OS_DEV_DIR/simulation/simenv/scripts/;sim.py -t ../../../../../7.X.X.M-tdao0751-MPLSCLI/engr/pal/schema/vc_sim/9900/mpls3.schema'
alias simfalcon='ssh -X tdao0751@falcon'
alias simvolga='ssh -X tdao0751@volga'
alias winter='ssh tdao0751@winter'
alias cs='cd $OS_DEV_DIR/sw; cscope -d;'
alias cs87='87r02; cd $OS_DEV_DIR/sw; cscope -d;'
alias snmpout='cd $OS_DEV_DIR/sw;cat management/snmp/mibs/snmp4j.out;'
alias cdsim='echo sim.py -t ../../../pal/schema/vc_sim/6560/bsvc.schema -f "OS6560" -o OS_7_X_X_6965_R01;echo sim.py -t ../../../pal/schema/agl2gre.schema;echo sim.py -c all;cd $OS_DEV_DIR/simulation/simenv/scripts/'
alias simboron=' ssh -X tdao0751@boron'

export P4USER=tdao0751
export P4PASSWD=tdao123321
export P4PORT=perforce:1810
