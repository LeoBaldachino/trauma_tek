# Reverse the screen orientation
xrandr -o inverted

# Set the background to a disco ball
feh --bg-fill https://preview.redd.it/wz80jkhcp6z61.jpg?auto=webp&s=e86693b09c01d9c784d500668106232ec7160294

# fuck up gamma and contrast
while true; do
    xgamma -gamma $(shuf -i 0-10 -n 1)
    xgamma -contrast $(shuf -i 0-10 -n 1)
    beep -f $(shuf -i 100-1000 -n 1)
    sleep 1
done

