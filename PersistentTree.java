import java.io.*;
import java.util.*;

public class Main {

  static InputReader scn = new InputReader(System.in);
  static PrintWriter out = new PrintWriter(System.out);

  public static void main(String[] args) throws Exception {
    // write your code here
  }
  private static class InputReader implements AutoCloseable {

    private static final int DEFAULT_BUFFER_SIZE = 1 << 16;


    private static final InputStream DEFAULT_STREAM = System.in;

    private static final int MAX_DECIMAL_PRECISION = 21;

    private int c;

    private final byte[] buf;
    private final int bufferSize;
    private int bufIndex;
    private int numBytesRead;

    private final InputStream stream;

    private static final byte EOF = -1;

    private static final byte NEW_LINE = 10;

    private static final byte SPACE = 32;

    private static final byte DASH = 45;

    private static final byte DOT = 46;
    private char[] charBuffer;
    private static final byte[] bytes = new byte[58];
    private static final int[] ints = new int[58];
    private static final char[] chars = new char[128];

    static {
      char ch = ' ';
      int value = 0;
      byte _byte = 0;
      for (int i = 48; i < 58; i++)
        bytes[i] = _byte++;
      for (int i = 48; i < 58; i++)
        ints[i] = value++;
      for (int i = 32; i < 128; i++)
        chars[i] = ch++;
    }

    public InputReader() {
      this(DEFAULT_STREAM, DEFAULT_BUFFER_SIZE);
    }
    public InputReader(int bufferSize) {
      this(DEFAULT_STREAM, bufferSize);
    }
    public InputReader(InputStream stream) {
      this(stream, DEFAULT_BUFFER_SIZE);
    }
    public InputReader(InputStream stream, int bufferSize) {
      if (stream == null || bufferSize <= 0)
        throw new IllegalArgumentException();
      buf = new byte[bufferSize];
      charBuffer = new char[128];
      this.bufferSize = bufferSize;
      this.stream = stream;
    }
    private byte read() throws IOException {

      if (numBytesRead == EOF)
        throw new IOException();

      if (bufIndex >= numBytesRead) {
        bufIndex = 0;
        numBytesRead = stream.read(buf);
        if (numBytesRead == EOF)
          return EOF;
      }

      return buf[bufIndex++];
    }
    private int readJunk(int token) throws IOException {

      if (numBytesRead == EOF)
        return EOF;
      do {

        while (bufIndex < numBytesRead) {
          if (buf[bufIndex] > token)
            return 0;
          bufIndex++;
        }
        numBytesRead = stream.read(buf);
        if (numBytesRead == EOF)
          return EOF;
        bufIndex = 0;

      } while (true);

    }
    public byte nextByte() throws IOException {
      return (byte) nextInt();
    }
    public int nextInt() throws IOException {

      if (readJunk(DASH - 1) == EOF)
        throw new IOException();
      int sgn = 1, res = 0;

      c = buf[bufIndex];
      if (c == DASH) {
        sgn = -1;
        bufIndex++;
      }

      do {

        while (bufIndex < numBytesRead) {
          if (buf[bufIndex] > SPACE) {
            res = (res << 3) + (res << 1);
            res += ints[buf[bufIndex++]];
          } else {
            bufIndex++;
            return res * sgn;
          }
        }
        numBytesRead = stream.read(buf);
        if (numBytesRead == EOF)
          return res * sgn;
        bufIndex = 0;

      } while (true);

    }
    public int[] nextIntArray(int n) throws IOException {
      int[] ar = new int[n];
      for (int i = 0; i < n; i++)
        ar[i] = nextInt();
      return ar;
    }
    public int[] nextIntArray1(int n) throws IOException {
      int[] ar = new int[n + 1];
      for (int i = 1; i <= n; i++)
        ar[i] = nextInt();
      return ar;
    }
    public void close() throws IOException {
      stream.close();
    }

  }
}
