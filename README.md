\mainpage

# Hybrid Power Inversion


This is sandbox code for my development of a hybrid controller for solar micro inverters.

This project is a microcontroller implementation of a new algorithm for power inversion using a switched differential inclusion to steer an output voltage trajectory to within some neighborhood around a reference signal. This neighborhood is known as the tracking band.

This project aims to address the following issues:
- Implement the control law on a Ti Piccolo
- Assess the performance of the hybrid algorithm compared to PWM, or bang-bang techniques
- Interface with a boost circuit
- MPPT
- Battery Charging


>The purpose of this project is to design and build a prototype to implement a control algorithm to invert mildly varying DC input power obtained from renewable sources into AC power to feed standard loads.

### Version     {#mainpage}
0.0.1

### Tech
- Ti Development boards
- Transphorm
- PV Cells
- C2000 Piccollo
- MATLAB


### Getting the repo

You need Git installed:

@code
$ cd sdpInverter
$ git clone [git-repo-url] sdpInverter
@endcode


### Plugins

We currently manage resources with these tools
* Github
* Dropbox
* Trello

## Development

### Todo's

- Write Tests - Buchi Automaton?
- Github Hygiene
- Maintain Code Comments for Doxygen
- Add Ti configuration files
- Test configuration
- Implement ADC on top of configuration
- Merge state machine, config, an

License
----

MIT


**Free Software, Hell Yeah!**

[Ryan Rodriguez]: http://empireryan.com
