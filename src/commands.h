
#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

#define

namespace atlib {
    namespace commands {

        /* A - ANSWER
            answers an incoming call
        */
        extern const char* ANSWER = "A";

        /* A/ - REPEAT
            repeats the last command given to the device
        */
        extern const char* REPEAT = "A/";

        /* D[phoneNumber][comandCharacter] - DIAL
            dials the phone number and attempts to call

            commandCharacter:
            P - pulse dial
            T - touch tone dial
            W - wait for second dial tone
            R - revert to answer mode after dialing
            @ - wait for one or more ringbacks (times out after 30 seconds)
            , - pause for the time specified in register S8 (usually 2 seconds)
            ; - remain in command mode after dialing
            ! - flash switch hook (hang up for half a second; transfers the call)
            L - redials last number
        */
        extern const char* DIAL = "D";

        /* E[n = 0] - ECHO
            sets whether the device should echo commands to the computer

            n: default = 0
            0 - off
            1 - on
        */
        extern const char* ECHO = "E";

        /* H<n> HOOK
            hangs up or picks up the phone

            n:
            0 - hangs up the phone
            1 - picks up the phone
        */
        extern const char* HOOK = "H";

        /* I<lineNum> - INFO
            requests a line of device information

            lineNum: integer 0 - 9
        */
        extern const char* INFO = "I"; // followed by "1" to "9" based on which firmware information line to pull

        /* L<volume> - LOUDNESS
            sets the speaker's volume level

            volume level:
            0 - off
            1 - low
            2 - medium
            3 - high
        */
        extern const char* LOUDNESS = "L"; // followed by "0" to "3", setting the loudness of the ringer speaker

        /* M<mode> - SPEAKER MODE
            sets the speaker's mode

            mode:
            0 - speaker off, completely silent during dialing
            1 - speaker on until remote carrier detected
            2 - speaker always on (data sounds are heard after connect)
        */
        extern const char* SILENT = "M";

        /* O - RETURN ONLINE
            returns the modem back to the normal connected state after being interrupted
        */
        extern const char* RETURN_ONLINE = "O";

        /* Q - QUIET MODE
            sets whether the device should return result codes for

        */
    }
}
#endif // COMMANDS_H_INCLUDED
