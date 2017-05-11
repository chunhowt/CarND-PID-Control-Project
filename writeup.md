## Getting the final parameter.
This is done by manually tuning by trial and error.

I initially started with the setting in lecture of 0.2 (P), 0.004 (I) and 3.0 (D).

Using this, I found that it oscillates a lot on the track 1. Upon thinking more carefully,
there might not be any systematic bias at all for our car in the simulator, I tried
a couple of i values and found that it indeed works best with value to 0. This makes sense
because the I component is used for correcting steady state error, and if there is none at all,
we can set it to zero to keep our controller simpler.

Now, at (0.2, 0.0, 3.0), it already works very well, but I noticed that the car is
still overshootting a bit. Based on my understanding of PID, it seems to be caused by P.
So, I did a binary search on P values, starting at 0.1 (but now the steering is not
sufficient in sharp corner), and then ended up finding 0.15 works well.

## P component
P component is the proportional component which is normally used to decrease the error
proportionally to the cross track error. Given that the track has curves, we need the P
component to help us to fix the error at the curve. I noticed during tuning that, if we
set the P coefficient to be too low, we are not able to correct the steering in sharp corners.
However, if the P coefficient is too high, it leads to overshooting at the corner.

## D component
D component is the derivative component which helps to decrease the overshooting effect
caused by the P component, making the car moves along the track smoothly. We need this
component to be relatively big (3) to help the car keep "stable" from overshootting
too much along the sharp curves.

## I component
I component is mostly used to eliminate steady state error, while the cons is it will also
increase the overshooting effect and the settling time. This is indeed what happens when
I tuned this component. I noticed that it is sufficient to set it to 0, most likely because
our car doesn't exactly has any steady state error. When I set it to higher than the optimum,
the car overshoots a lot, and it takes a long time (or never) for the car to stabilize
in the end.
