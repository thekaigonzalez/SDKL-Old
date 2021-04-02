#include <vector>
#include <string>
namespace sdk {
    /**
     * A Basic Ordered Map.
     *
     *
     *
     * @tparam C
     */
    template<typename C>
    class ordered_map {
    private:
        std::vector<C>vec_ptr{};
        std::vector<C>vec_keyptr_t{};
        int ipos=0;
    public:
        /**
         * Pushes <stuff> to the ordered map.
         * @param stuff
         */
       ordered_map(std::vector<C>stuff) {
           for (const auto& i : stuff) {
                vec_ptr.push_back(i);
           }
       }
       /**
        * Adds an Item to the array.
        * @param items
        */
       void add(C * items) {
           vec_ptr.push_back(items);
       }
       /**
        * An Overloaded Operator to add(items), Adds an item with a value specified to that specific macro.
        * @param key
        * @param value
        */
       void add(C & key, C value) {
           vec_ptr.push_back(key);
           vec_keyptr_t.push_back(value);
       }
       /**
        * Gets the first component in the map and returns it. While removing it completely.
        * @return
        */
       C shift() {

       }
       /**
        * Removes an item from the array at <index>
        * @see SDK.OrderedMap.shift();
        */
       void remove(int index) {
           vec_ptr[index] ='\0';
       }
       /**
        * Removes a key, As well as it's value.
        * @see SDK.OrderedMap.remove(<int>);
        * @param MacroDef
        */
       void removeMacroFirst(C& MacroDef) {
           for (int i = 0; i < vec_ptr.size(); ++i) {
               if (vec_ptr[i] == MacroDef) {
                   vec_ptr[i] = '\0';
                   vec_keyptr_t[i] = '\0';
               }
           }
       }
       /**
        * Gets the first macro of the Map.
        */
       C first() {
           return vec_ptr[0];
       }
       /**
        * Gets the last member of the list.
        * @return
        */
       C last() {
           return vec_ptr[vec_ptr.size()-1];
       }
       /**
        * Finds a key and returns it's value.
        * @param Macro
        * @return Macro.SDKValueType
        */
       C findOf(C Macro) {
           for (int i = 0; i < vec_ptr.size(); ++i) {
               if (vec_ptr[i] == Macro)
                   return vec_keyptr_t[i];
           }
       }
       int lastOf() {
            return vec_ptr.size();
       }
       int indexOf() {
			return 1;
       }
       int size() {
            return vec_ptr.size();
       }
       void operator+=(std::vector<C>T) {
           for (int i = 0; i < T.size(); ++i) {
               vec_ptr.push_back(T[i]);
               vec_keyptr_t.push_back(T[i+1]);
           }
       }
       C atIpos() {
           return vec_ptr[ipos];
       }
       void operator++() {
           ipos++;
       }
        C operator[](int index) {
           return vec_ptr[index];
       }
       C operator[](C & macro) {
           for (int i = 0; i < vec_ptr.size(); ++i) {
               if (vec_ptr[i] == macro)
                   return vec_keyptr_t[i];
           }
       }
       ordered_map() = default;
    };
}