light -S 50

statusbar &
pulseaudio --exit-idle-time=-1 &> /dev/null &

xsetroot -solid "#FFFFFF"

exec dwm
