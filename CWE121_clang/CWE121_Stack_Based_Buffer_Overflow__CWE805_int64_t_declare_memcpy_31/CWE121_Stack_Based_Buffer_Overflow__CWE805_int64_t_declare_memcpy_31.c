/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memcpy_31.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memcpy
 *    BadSink : Copy int64_t array to data using memcpy
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memcpy_31_bad()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = dataBadBuffer;
    {
        int64_t * dataCopy = data;
        int64_t * data = dataCopy;
        {
            int64_t source[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memcpy(data, source, 100*sizeof(int64_t));
            printLongLongLine(data[0]);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    {
        int64_t * dataCopy = data;
        int64_t * data = dataCopy;
        {
            int64_t source[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memcpy(data, source, 100*sizeof(int64_t));
            printLongLongLine(data[0]);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memcpy_31_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memcpy_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memcpy_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
